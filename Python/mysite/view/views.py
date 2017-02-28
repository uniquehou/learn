from django.http import HttpResponse
from django.template import Template, Context
from django.shortcuts import render_to_response
from django.template.loader import get_template

def sum(request, n):
	try:
		sum = 0
		for i in range(int(n)):
			sum += i
		return HttpResponse("The sum is %d" % sum)
	except:
		return HttpResponse(n)

def hello(request):
	t = Template("{% for k,v in d.items %} {{k}}=>{{v}} {% endfor %}")
	c = Context({'d':request.GET})
	html = t.render(c)
	return HttpResponse(html)

def welcome(request, name):
	t = get_template('welcome.html')
	content = dict(zip(list("abcdefg"), range(7)))
	c = Context({'content':content})
	html = t.render(c)
	return HttpResponse(html)
