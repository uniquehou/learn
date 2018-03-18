from django.db import models

class Question(models.Model):
    correct_option_choice = (
        ('1', '选项A', ),
        ('2', '选项B', ),
        ('3', '选项C', ),
        ('4', '选项D', )
    )

    content = models.CharField(u'题目', max_length=300)
    option1 = models.CharField(u'选项A', max_length=300)
    option2 = models.CharField(u'选项B', max_length=300)
    option3 = models.CharField(u'选项C', max_length=300)
    option4 = models.CharField(u'选项D', max_length=300)
    correct_option = models.CharField(u'正确选项', max_length=1, choices=correct_option_choice)

    class Meta:
        verbose_name = '题库'

    def __str__(self):
        return self.content