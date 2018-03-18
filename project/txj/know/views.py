from django.shortcuts import render
from django.http import HttpResponse
from django.views.generic import View
from django.core.cache import cache
from datetime import datetime
import json
from random import sample
from know.models import Question

class IndexView(View):
    def get(self, request):
        return render(request, 'know/index.html', {'one': 'one', 'many': 'many', 'index': 1})


def start(request):
    if not cache.get('question'):
        return HttpResponse(json.dumps({'status': 2}))
    oper = request.GET.get('oper')
    if oper == "stayon":
        cache.set('start', '1', timeout=600)
    elif oper == "challenge":
        if cache.get('start') != '1':
            return HttpResponse(json.dumps({'status': 0}))
    return HttpResponse(json.dumps({'status': 1}))


class oneToManyView(View):
    # return option of 1
    def get(self, request, oper, index):
        question = json.loads(cache.get('question'))[str(index)]
        return_data = {
            'index': index,
            'grade': cache.get('grade'),
            'content': question['content'],
            'option1': question['option1'],
            'option2': question['option2'],
            'option3': question['option3'],
            'option4': question['option4'],
            'correct_option': question['correct_option']
        }
        request.session['oper'] = oper
        request.session['index'] = index
        return render(request, 'know/oneToMany.html', return_data)

    # 验证答案并返回下一问题
    def post(self, request, oper, index):
        answer = request.POST.get('answer')
        correct_option = request.POST.get('correct_option')
        oper = request.session.get('oper')
        index = request.session.get('index')

        # 回答错误
        if answer != correct_option:
            # the one is error
            if oper == "one":
                cache.set('start', '0')
            return_data = {
                'status': 0,
                'grade': cache.get('grade'),
            }
            return HttpResponse(json.dumps(return_data))

        # 回答正确
        else:
            cache.set('grade', cache.get('grade')+1 )
            if cache.get('start') == '0':
                return_data = {
                    'status': 2,
                    'grade': cache.get('grade')
                }
            elif index == 10:
                return_data = {
                    'status': 3,
                    'grade': cache.get('grade')
                }
            else:
                request.session['index'] = int(index)+1
                question = json.loads(cache.get('question'))[str(index)]
                return_data = {
                    'status': 1,
                    'index': index,
                    'grade': cache.get('grade'),
                    'content': question['content'],
                    'option1': question['option1'],
                    'option2': question['option2'],
                    'option3': question['option3'],
                    'option4': question['option4'],
                    'correct_option': question['correct_option']
                }
            return HttpResponse(json.dumps(return_data))


class AdminView(View):
    def get(self, request, oper):
        if oper == 'refresh':
            # 生成题并缓存
            question = sample( list(Question.objects.all()), 10)
            question_data = {}
            for index, q in enumerate(question):
                question_data[str(index+1)] = {
                    'content': q.content,
                    'option1': q.option1,
                    'option2': q.option2,
                    'option3': q.option3,
                    'option4': q.option4,
                    'correct_option': q.correct_option
                }
            question_json = json.dumps(question_data)
            cache.set('question', question_json, timeout=600)
            cache.set('grade', 0, timeout=600)
            return HttpResponse(json.dumps({'status': 1}))
        else:
            return render(request, 'know/admin.html', {'oper': 'refresh'})


def set_cache(request):
    cache.set('foo', datetime.now().strftime("%H:%M:%S"), timeout=10)
    return HttpResponse("success")

def get_cache(requst, var):
    if not cache.get(var):
        return HttpResponse('not found')
    return HttpResponse(cache.get(var))
