import os
PATH = os.getcwd()
ignore = [".git",".DS_store"]
def addTitle(title,dep,fo) : 
	str = ""
	for i in range(dep) : str = str + "#"
	str = str + " " + title + "\n"
	# print(str)
	fo.write(str)

def addCpp(filePath,fileName,fo) :
	fileName = fileName[0:-4]
	fileObj = open(filePath,"r")
	str0 = "* " + fileName + "\n"
	str1 = "```c++\n"
	str3 = "```\n"
	str2 = fileObj.read()
	st, ed = str2.find("/*"), str2.find("*/")
	fo.write(str0)
	if st == 0 :
		fo.write(str2[st+2:ed]+"\n")
	else :
		ed = -3
	fo.write(str1)
	fo.write(str2[ed+3:]+"\n")
	fo.write(str3)
	fileObj.close()

def addMd(filePath,fileName,fo) :
	fileName = fileName[0:-3]
	str1 = "* " + fileName + "\n"
	fileObj = open(filePath,"r")
	str2 = fileObj.read() + "\n"
	fileObj.close()
	fo.write(str1)
	fo.write(str2)

def walkFile(mainDir,fo) :
	base = len(mainDir.split("/"))
	print(base)
	for root, dirList, fileList in os.walk(mainDir) :
		currDir = root.split("/")[-1]
		depth = len(root.split("/")) - base
		fl = 0
		for ig in ignore : 
			if ig in root.split("/") :
				fl = 1
		if fl == 1 :
			continue
		addTitle(currDir,depth,fo)	
		for file in fileList :
			if file.find(".cpp") > 0 :
				filePath = os.path.join(root,file)
				addCpp(filePath,file,fo)
			elif file.find(".md") > 0 :
				filePath = os.path.join(root,file)
				addMd(filePath,file,fo)
		 	# print("files:  " + os.path.join(root,f))


def main(fo) : 
	walkFile(PATH,fo)

if __name__ == '__main__' :
	fo = open(PATH+"/template.md","a")
	main(fo)
	fo.close()