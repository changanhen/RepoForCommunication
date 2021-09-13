from bs4 import BeautifulSoup
import re
import urllib.request
import sys
import sqlite3

def main():
    baseurl = "http://ehall.xjtu.edu.cn/jwapp/sys/wdkb/*default/index.do?amp_sec_version_=1&gid_=S3dzUjIyZ1lnbzdra0gwMk1BaWwwUkpQUHp1VlY3MHRiWDNpRW9FeU9qb2tSUDhKbStqUVlxZllYR2YxU1doRmFTdlpnVWhWUWxRamtieUxvZE1rZEE9PQ&EMAP_LANG=zh&THEME=millennium#/xskcb"    # 网址
    # 测试
    response = askUrl(baseurl)
    try:
        print(response.read().decode('utf-8'))
    except Exception as result:
        print("无法读取，错误如下：")
        print(result)
    saveData = ".\\课表.xlsx"   #保存路径



# 请求网址
def askUrl(baseurl):
    response = ""   # 初始化字符串
    try:    # 捕获异常码
        response = urllib.request.urlopen(baseurl, timeout=1)
    except Exception as result:
        print("打开失败")
        print(result)
    finally:
        return response



# 获取数据
def getData(baseUrl):
    datalist = []
    return datalist



# 保存数据
def saveData(savepath):
    print("save...")



# 程序入口
if __name__ == "__main__":
    main()