from django.contrib import admin
from know.models import *
import xadmin
from xadmin import views

class QuestionAdmin(object):
    list_display = ('id', 'content', 'option1', 'option2', 'option3', 'option4', 'correct_option')
    ordering = ('id', )

xadmin.site.register(Question, QuestionAdmin)

class GlobalSetting(object):
    site_title = '天行健知识竞赛管理系统'
    site_footer = '天行健'

xadmin.site.register(views.CommAdminView, GlobalSetting)
