from django.db import models

class User(models.Model):
	username = models.CharField(max_length=50)
	sex = models.SmallIntegerField()
	password = models.CharField(max_length=30)

	def __str__(self):
		return self.username + '  ' + self.password

class Even(models.Model):
	name = models.CharField(max_length=100)
	describe = models.TextField()
	remark = models.CharField(max_length=200)
	finish_time = models.DateTimeField()
	mail = models.BooleanField()
	mail_address = models.EmailField()
	# mail_time = models.DateTimeField(blank=True)
	wechat = models.BooleanField()
	wechat_name = models.CharField(max_length=50)
	# wechat_time = models.DateTimeField(blank=True)
	user_id = models.ForeignKey(User)

	def __str__(self):
		return self.name + '  ' + str(self.finish_time)


