from django.http import HttpResponse, HttpResponseRedirect
from django.template import Template, RequestContext
from django.shortcuts import render, redirect
from django.template.loader import get_template
from django.core.mail import send_mail
from user.models import User, Even

def index(request):
	return render(request, 'user/index.html')

def login(request):
	if request.method == 'GET':
		return render(request, 'user/login.html')
	else:
		username = request.POST['username']
		password = request.POST['password']
		user = User.objects.filter(username=username)[0]
		if user.password == password:
			request.session['user_id'] = request.user.id
			return HttpResponseRedirect('info')
		else:
			return HttpResponse("用户名或密码错误，请重新<a href='/index/login'>登录</a>")

def sign(request):
	if request.method == 'GET':
		return render(request, 'user/sign.html')
	else:
		username = request.POST['username']
		sex = request.POST['sex']
		password = request.POST['password']
		user = User(request.POST)
		user.save()
		return HttpResponseRedirect('login')

def info(request):
	try:
		request.session['user_id']
		if request.method == 'POST':
			even = Even(
				name = request.POST['name'],
				describe = request.POST['describe'],
				remark = request.POST['remark'],
				finish_time = request.POST['finish_time'],
				mail = True if request.POST['mail'] else False,
				mail_address = request.POST['mail_address'],
				wechat = True if request.POST['wechat'] else False,
				wechat_name = request.POST['wechat_name'],
				user_id = User.objects.filter(id=request.session['user_id'])[0]
				)
			even.save()

		evens = Even.objects.filter( user_id = request.session['user_id'] )
		return render(request, 'user/info.html', {'evens':evens})
	except KeyError:
		return HttpResponseRedirect('login')

def email(request):
	send_mail('test subject', 'test contect', 'uniquehou@aliyun.com', ['919863463@qq.com'], fail_silently=True)
	return HttpResponse('Successfully')
	
