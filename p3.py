class Set:
    def __init__(self, initcount):
        self._s = []
        for i in range(initcount):
            e = int(input("Enter the elements:"))
            self.add(e)

    def getset(self):
        return self._s

    def __str__(self):
        string = "{\n"
        for i in range(len(self.getset())):
            string += str(self.getset()[i])
            if i != len(self.getset()) - 1:
                string += ","
        string += "}\n"
        return string

    def __len__(self):
        return len(self._s)
    
    def __contains__(self, e):
        return e in self._s
    
    def isEmpty(self):
        return len(self._s) == 0
    
    def add(self, e):
        if e not in self._s:
            self._s.append(e)

    def remove(self, e):
        if e in self._s:
            self._s.remove(e)

    def union(self, setB):
        newSet = self
        for i in setB.getset():
            if i not in self.getset():
                newSet.add(i)

        return newSet
    def intersection(self,setB):
        newSet=Set(0)
        for i in range(len(self.getset())):
            for j in range(len(setB.getset())):
                if self.getset()[i]==setB.getset()[j]:
                    newSet.add(self.getset()[i])
        return newSet



def createset():
    n = int(input("Enter the number of elements:"))
    return Set(n)

s1 = createset()
print(str(s1))

while True:
    print("**************************")
    print("1. Union")
    print("2.Add")
    print("3.Remove")
    print('4.Size')
    print('5.Intersection')
    ch = int(input("Enter your choice:"))
    if ch == 1:
        print("Create set B")
        s2 = createset()
        s3 = s1.union(s2)
        print("Union of two sets:", str(s3))
    
    if ch==2:
        num1=int(input("Enter the number of elements to be added:"))
        for i in range(num1):
            ele=int(input("Enter the elements:"))
            s1.add(ele)
        print("New set A:",str(s1))

    if ch==3:
        ele=int(input("Enter the element to be removed:"))
        s1.remove(ele)
        print("After removal:",s1)

    if ch==4:
        print("Set A contains:",len(s1)," elements")
        
    if ch==5:
        print("Create setB:")
        s5=createset()
        s6=s1.intersection(s5)
        print("Intersection of 2 sets:",str(s6))
    
    
    else:
        break
