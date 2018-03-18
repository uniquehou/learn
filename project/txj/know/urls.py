from django.conf.urls import url
from know.views import *
from know import views

app_name = 'know'
urlpatterns = [
    url(r'^index/$', IndexView.as_view(), name='home'),
    url(r'^start/$', views.start, name='start'),   # start challenge
    url(r'^oneToMany/(?P<oper>one|many)/(?P<index>\d+)/$', views.oneToManyView, name='oneToMany'),
    url(r'^admin/(?P<oper>.*)$', AdminView.as_view(), name='admin'),
    url(r'^set_cache/$', set_cache, name='set_cache'),
    url(r'^get_cache/(?P<var>\w+)/$', get_cache, name='get_cache'),
]