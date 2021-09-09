#Written by nocriz, modified by Aya
import requests
import re

print('Score Generator 2021')
print('Written by nocriz, modified by Aya\n')

scorring = [[1,2,3,4,5,6,7],    # day 1
            [1,2,3,4,5,6],    # day 2
            [1,2,3,4,5,6],    # day 3
            [1,2,3,4,5,6],    # day 4
            [1,2,3,4,5,6],    # day 5
            [1,2,3,4,5,6],    # day 6
            [1,2,3,4,5,6,7],    # day 7
            [1,2,3,4,5,6,7],    # day 8
            [1,2,3,4,5,6],    # day 9
            [1,6],    # day 10
            [0,6,12,18,24,30]]
contest_id = [63,64,65,66,67,68,69,70,71,72,73]
contest_name = ["Day1绪论","Day2贪心","Day3分治","Day4搜索","Day5动态规划","Day6数据结构","Day7图论","Day8数学","Day9字符串","Day10习题课","期末考试"]
score = []
for i in range(1400):
    score.append([])
username = [""]*1400
sign = [""]*1400
#获取成绩
print('Get Score start')
for ech in range(len(contest_id)):
    cr = requests.get("https://oj.xjtuicpc.com/contest/%d/ranklist"%contest_id[ech]).text
    
    cr = cr.split("<tr>")
    for i in cr[2:]:
        cid = int(i.split('href="/user/')[1].split('"')[0])
        #print(cid)
        cname = i.split('href="/user/')[1].split('>')[1].split('<')[0]
        try:
            cscore = int("".join(i.split('<a href="/submission/')[1:]).count("score score_10"))
        except:
            cscore = 0
        username[cid] = cname
        try:
            score[cid].append(scorring[ech][cscore])
        except:
            print(ech,cscore,scorring[ech])
    for i in range(1400):
        if len(score[i]) < ech+1:
            score[i].append(0)
    print("%s finished"%contest_name[ech])
#获取签名
print('\nGet Signature start')
for i in range(1400):
    if username[i]!="":
        sg = requests.get("https://oj.xjtuicpc.com/user/%d"%i).text
        sg = re.search("<div style=\"position: relative; overflow: hidden; \">.*</p>",sg,re.DOTALL)
        if sg != None:
            sg = sg.group(0).replace('\n',' ').replace('\r','')
            sg = sg.replace(',','，')
            sign[i] = re.sub("<.*?>",'',sg,re.DOTALL)
print('Get Signature finished\n')
#保存
print('Write csv start')
with open("result.csv","w") as opt:
    for i in range(1400):
        if username[i]!="":
            opt.write("%d,\"%s\","%(i,username[i]))
            opt.write("%s,"%sign[i])
            opt.write("10,")
            opt.write("".join([str(j)+"," for j in score[i]]))
            opt.write(str(10 + sum(score[i]))+"\n")
        if i == 0:
            opt.write("用户id,\"用户名\",\"个性签名\",\"考勤\",")
            opt.write("".join([contest_name[j]+"," for j in range(len(score[i]))]))
            opt.write("总分\n")
print('Write csv finished')
