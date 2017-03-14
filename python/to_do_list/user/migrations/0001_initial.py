# -*- coding: utf-8 -*-
# Generated by Django 1.10.3 on 2017-03-02 07:51
from __future__ import unicode_literals

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='even',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=100)),
                ('describe', models.TextField()),
                ('remark', models.CharField(max_length=200)),
                ('finish_time', models.DateTimeField()),
                ('mail', models.BooleanField()),
                ('mail_address', models.EmailField(max_length=254)),
                ('mail_time', models.DateTimeField()),
                ('wechat', models.BooleanField()),
                ('wechat_name', models.CharField(max_length=50)),
                ('wechat_time', models.DateTimeField()),
            ],
        ),
        migrations.CreateModel(
            name='user',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('username', models.CharField(max_length=50)),
                ('sex', models.SmallIntegerField()),
                ('password', models.CharField(max_length=30)),
            ],
        ),
        migrations.AddField(
            model_name='even',
            name='user_id',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='user.user'),
        ),
    ]