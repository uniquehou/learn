# -*- coding: utf-8 -*-
# Generated by Django 1.10.3 on 2017-03-04 08:40
from __future__ import unicode_literals

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('user', '0002_auto_20170304_1622'),
    ]

    operations = [
        migrations.AlterField(
            model_name='even',
            name='mail_time',
            field=models.DateTimeField(blank=True),
        ),
        migrations.AlterField(
            model_name='even',
            name='user_id',
            field=models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='user.User'),
        ),
        migrations.AlterField(
            model_name='even',
            name='wechat_time',
            field=models.DateTimeField(blank=True),
        ),
    ]
