import requests
from bs4 import BeautifulSoup

url = 'http://trains.ctrip.com/TrainBooking/Ajax/SearchListHandler.ashx?Action=getSearchList'
data = 'value={"IsBus":false,"Filter":"0","Catalog":"","IsGaoTie":false,"IsDongChe":false,"CatalogName":"","DepartureCity":"changzhi","ArrivalCity":"yuci","HubCity":"","DepartureCityName":"闀挎不","ArrivalCityName":"姒嗘","DepartureDate":"2017-02-10","DepartureDateReturn":"2017-02-12","ArrivalDate":"","TrainNumber":""}'

headers = {'Host':'trains.ctrip.com', \
'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0', \
'Accept':'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8', \
'Accept-Language':'zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3', \
'Accept-Encoding':'gzip, deflate', \
'Content-Type':'application/x-www-form-urlencoded; charset=utf-8', \
'If-Modified-Since': 'Thu, 01 Jan 1970 00:00:00 GMT', \
'Referer': 'http://trains.ctrip.com/TrainBooking/Search.aspx?from=changzhi&to=yuci&day=2&number=&fromCn=%B3%A4%D6%CE&toCn=%D3%DC%B4%CE', \
'Content-Length':'320', \
'Cookie':'Session=SmartLinkCode=U155952&SmartLinkKeyWord=&SmartLinkQuary=&SmartLinkHost=&SmartLinkLanguage=zh; _abtest_userid=e383a187-5034-45cb-a7ca-968111eb01fd; _bfa=1.1483928344755.1ktosu.1.1486623343886.1486640355829.6.47; _ga=GA1.2.1824834440.1483928348; traceExt=campaign=CHNbaidu81&adid=index; _jzqco=%7C%7C%7C%7C1486623353170%7C1.787172478.1483928347739.1486640368971.1486640394687.1486640368971.1486640394687.undefined.0.0.24.24; __zpspc=9.5.1486640358.1486640394.3%231%7Cbaidu%7Ccpc%7Cbaidu81%7C%25E6%2590%25BA%25E7%25A8%258B%7C%23; appFloatCnt=16; page_time=1485691097705%2C1485691113959%2C1485691252073%2C1485691309920%2C1486458582302%2C1486458620225%2C1486462086879%2C1486623352714%2C1486640366961%2C1486640391886; guid__=b2821346-bb0d-4a91-bfba-0ca628d2aa0f; Union=SID=155952&AllianceID=4897&OUID=baidu81|index|||; MKT_Pagesource=PC; adscityen=Jincheng; manualclose=1; _bfi=p1%3D108002%26p2%3D108001%26v1%3D47%26v2%3D46; ASP.NET_SessionSvc=MTAuOC4xODkuNjd8OTA5MHxqaW5xaWFvfGRlZmF1bHR8MTQ3MTUyMDQ4OTM3OA', \
'Connection':'keep-alive'}

r = requests.post(url, data, headers = headers)
js = r.json()
print(js.keys())