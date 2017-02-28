from django.contrib import admin
from .models import Teacher, Student, Course

class TeacherAdmin(admin.ModelAdmin):
	list_display = ('name',)
	search_field = ('name',)


class StudentAdmin(admin.ModelAdmin):
	list_display = ('name',)
	search_field = ('name',)

class CourseAdmin(admin.ModelAdmin):
	list_display = ('name',)
	search_field = ('name',)

admin.site.register(Teacher, TeacherAdmin)
admin.site.register(Student, StudentAdmin)
admin.site.register(Course, CourseAdmin)
