from django.conf.urls import url
from django.contrib import admin
from course import views

urlpatterns = [
    url(r'^index$', views.index),
]