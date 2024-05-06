class hashtable:
    def __init__(self):
        self.m=int(input("Enter the size of hash table:"))
        self.hashTable=[None]*self.m
        self.elecount=0
        self.comparisons=0
        print(self.hashTable)

    def hashFunction(self,key):
        return(key%self.m)
    
    def isFull(self):
        if(self.elecount==self.m):
            return True
        else:
            return False
    
    def linearprobe(self,key,data):
        index=self.hashFunction(key)
        compare=0
        i=0
        while self.hashTable[index] is not None:
            index=(index+i)%self.m
            compare=compare+1
            i=i+1
        self.hashTable[index]=[key,data]
        self.elecount+=1
        print("data inserted at index:",index)
        print(self.hashTable)
        print("Number of comparisons:",compare)

    def getlinear(self,key,data):
        index=self.hashFunction(key)
        i=0
        while self.hashTable[index] is not None:
            if self.hashTable[index]==[key,data]:
                return index
            i=i+1
            index=(index+i)%self.m
        return None
    
    def quadraticprobe(self,key,data):
        index=self.hashFunction(key)
        i=0
        compare=0
        while self.hashTable[index] is not None:
            index=(index+i*i)%self.m
            i=i+1
            compare=compare+1
        self.hashTable=[key,data]
        self.elecount+=1
        print("data inserted at index:",index)
        print(self.hashTable)
        print("Number of comparisons:",compare)

    def getquad(self,key,data):
        index=self.hashFunction(key)
        i=0
        while self.hashtable[index] is not None:
            if self.hashTable[key,data]==[key,data]:
                return index
            i=i+1
            index=(index+i*i)%self.m
        return None
    def insertvialinear(self,key,data):
        if self.isFull():
            print("Table is Full")
            return False
        index=self.hashFunction(key)
        if self.hashTable[index] == None:
            self.hashTable[index]=[key,data]
            self.elecount+=1
            print("Data inserted at index:",index)
            print(self.hashTable)
        else:
            print("Collision has occured:")
            self.linearprobe(key,data)
    def insertviaquad(self,key,data):
        if self.isFull():
            print("Table is Full:")
            return False
        index=self.hashFunction(key)
        if self.hashTable[index] is not None:
            self.hashTable[index]=[key,data]
            self.elecount+=1
            print("Data inserted at index:",index)
            print(self.hashTable)
        else:
            print("Collision has occured:")
            self.quadraticprobe(key,data)


def menu():
    obj=hashtable()

    ch1=0
    while(ch1!=3):
        print("1.Linear Probing")
        print("2.Quadratic Probing")
        print("3.Exit")
        ch1=int(input("Enter your choice:"))
        if(ch1==1):
            ch2=0
            while(ch2!=3):
                print("1.Insert")
                print("2.Search")
                print("3.Exit")
                ch2=int(input("Enter your choice:"))
                if(ch2==1):
                    a=int(input("Enter the phone number:"))
                    b=input("Enter the name:")
                    obj.insertvialinear(a,b)
                elif(ch2==2):
                     c=int(input("Enter the phone number:"))
                     d=input("Enter the name:")
                     f=obj.getlinear(c,d)
                     if(f==None):
                         print("Key not found:")
                     else:
                         print("Key found at index",f)
        elif(ch1==2):
             ch2=0
             obj2=hashtable()
             while(ch2!=3):
                print("1.Insert")
                print("2.Search")
                print("3.Exit")
                ch2=int(input("Enter your choice:"))
                if(ch2==1):
                    a=int(input("Enter the phone number:"))
                    b=input("Enter the name:")
                    obj2.insertviaquad(a,b)
                elif(ch2==2):
                     c=int(input("Enter the phone number:"))
                     d=input("Enter the name:")
                     f=obj2.getquad(c,d)
                     if(f==None):
                         print("Key not found:")
                     else:
                         print("Key found at index",f)

menu()




