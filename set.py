class Set: 
    def __init__(self):
        self.s=[]
        size=int(input("enter the size of set:"))
        for i in range(size):
            x=int(input("enter the element of set:"))
        
            if x not in self.s:
                self.s.append(x)



    def displaySet(self):
        for i in self.s:
            print("ele->"," ",i)

    def removeFromSet(self,val):
        if val in self.s:
            self.s.remove(val)

    def checkPresent(self,val):
        if val in self.s:
            print(val ," is present in the set")
        else:
            print("val is not present in set")
    
    
    def sizeOfSet(self):
        print("size of given set is: ",len(self.s))


    def intersectionOfSet(self,B):
        # print(B.s)
        intersectionSet=[]
        for i in self.s:
            if i in B.s:
                    intersectionSet.append(i)

        print("intersection of set is:")
        for x in intersectionSet:
            print(x)

    
    def unionOfSet(self,B):
        unionSet=[]
        for i in self.s:
            unionSet.append(i)

        for j in B.s:
            if j not in unionSet:
                unionSet.append(j)

        print("union of sets is:")

        for x in unionSet:
            print(x)

    
    def difference(self,B):
        diff=[]
        for i in self.s:
            if i not in B.s:
                diff.append(i)

        for x in diff:
            print(x)
            

    def checkSubset(self,Subset):
        count=0
        for i in Subset.s:
            if i in self.s:
                count=count+1
        
        if count==len(Subset.s):
            print("subset is present")
        else:
            print("subset is not present")



obj=Set()

obj.displaySet()
# obj.removeFromSet(10)
# obj.displaySet()
# obj.checkPresent(20)
# obj.sizeOfSet()
# print("another set",end="")
obj2=Set()


obj2.displaySet()


# obj.intersectionOfSet(obj2)

# obj.unionOfSet(obj2)
# obj.difference(obj2)
obj.checkSubset(obj2)