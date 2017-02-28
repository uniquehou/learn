from django.db import models

class Teacher(models.Model):
	name = models.CharField(max_length=100)
	age = models.IntegerField()

	def __str__(self):
		return "%s" % (self.name)

	class Meta:
		verbose_name = "教师"

class Student(models.Model):
	name = models.CharField(max_length=100)
	age = models.IntegerField()

	def __str__(self):
		return "%s" % (self.name)

	class Meta:
		verbose_name = "学生"

class Course(models.Model):
	name = models.CharField(max_length=100)
	teacher = models.ForeignKey(Teacher)
	students = models.ManyToManyField(Student)

	def __str__(self):
		return "%s" % (self.name)

	class Meta:
		verbose_name = "课程"
