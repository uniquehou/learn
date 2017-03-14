from django.conf.urls import url, include
import remain
from . import views

urlpatterns = [
	url(r'^$', views.index),
	url(r'^login$', views.login),
	url(r'^sign$', views.sign),
	url(r'^info$', views.info),
	url(r'^email$', views.email),
]