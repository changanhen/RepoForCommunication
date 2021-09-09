try:
    fp1 = open("gushi.txt", "r")
    fp2 = open("copy.txt", "w")
    while True:
        try:
            line = fp1.readline()
            if (line == ""):
                break
            fp2.writelines(line)
        except Exception as abn:
            print(abn)
except Exception as result:
    print(result)