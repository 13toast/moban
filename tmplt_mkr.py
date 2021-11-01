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
	str1 = "* " + fileName + "\n" + "```c++\n"
	str3 = "```\n"
	fileObj = open(filePath,"r")
	str2 = fileObj.read() + "\n"
	fileObj.close()
	fo.write(str1)
	fo.write(str2)
	fo.write(str3)


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
			if (file.find(".cpp") > 0) :
		 		filePath = os.path.join(root,file)
		 		addCpp(filePath,file,fo)
		 	# print("files:  " + os.path.join(root,f))


def main(fo) : 
	walkFile(PATH,fo)

if __name__ == '__main__' :
	fo = open(PATH+"/template.md","a")
	main(fo)
	fo.close()