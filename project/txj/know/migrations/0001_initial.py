# -*- coding: utf-8 -*-
# Generated by Django 1.11.2 on 2018-03-12 14:01
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Question',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('content', models.CharField(max_length=300, verbose_name='题目')),
                ('option1', models.CharField(max_length=300, verbose_name='选项A')),
                ('option2', models.CharField(max_length=300, verbose_name='选项B')),
                ('option3', models.CharField(max_length=300, verbose_name='选项C')),
                ('option4', models.CharField(max_length=300, verbose_name='选项D')),
                ('correct_option', models.CharField(choices=[('选项A', '1'), ('选项B', '2'), ('选项C', '3'), ('选项D', '4')], max_length=1, verbose_name='正确选项')),
            ],
        ),
    ]
