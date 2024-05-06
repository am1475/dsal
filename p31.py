class Set:
    def __init__(self,initelements):
        self._s=[]
        for e in range(initelements):
            ele=int(input("Enter the number of elements"))
            self.add(ele)

    def getset(self):
        return self._s


    def __str__(self):
        string="\n{"
        for i in range(len(self.getset())):
            string=string+str(self.getset()[i])
            if i!=len(self.getset())-1:
                string=string+","
        string+="}\n"
        return string
    def __len__(self):
        return len(self._s)
    
    def add(self,e):
        if e not in self._s:
            self._s.append(e)

    def remove(self,e):
        if e in self._s:
            self._s.remove(e)

    def union(self,setB):
        newset=self
        for e in setB.getset():
            if e not in self.getset():
                newset.add(e)
        return newset
    
def createset():
    n=int(input("Enter the number of elements:"))
    return Set(n)

s1=createset()
print(str(s1))

while(True):
    print("1.Union")
    print("2.Exit:")
    ch=int(input("Enter your choice:"))
    if(ch==1):
        s2=createset()
        s3=s1.union(s2)
        print("Union of 2 sets:",str(s3))
    else:
        break
