from Record import Record

class DoubleHash:

    def __init__(self):
        self.size=int(input("enter the size of hashtable: "))
        self.elecount=0
        self.comparisons=0
        self.Table=list(None for i in range(self.size))


    def isFull(self):
        if self.elecount==self.size:
            return True
        else:
            return False
        
    def h1(self,ele):
        return ele % self.size
    

    def h2(self,ele):
        return 5-(ele % 5)
    

    # def DobleHashing(self,inputRec):
    #     indeFound=False
    #     limit=self.size

    #     i=1
    #     while ( i<=limit ):
    #         newIndex=(self.h1(inputRec.getNumber())+i*self.h2(inputRec.getNumber())) %self.size

    #         if self.Table[newIndex]==None:
    #             indeFound=True
    #             break
    #         else:
    #             i+=1

    #     return indeFound,newIndex


    def insert(self,inputRecord):
        if self.isFull():
            print("cant insert in double hashtable ")
            return
        
        index=self.h1(inputRecord.getNumber())

        if(self.Table[index]==None):
            self.Table[index]=inputRecord
            print("record inserted")
            return
        else:
            limit=self.size
            i=1
            while(i<limit):
                newindex=(self.h1(inputRecord.getNumber())+i*self.h2(inputRecord.getNumber()))%limit

                if(self.Table[newindex]==None):
                    self.Table[newindex]=inputRecord
                    print("record inserted")
                    return
                else:
                     i+=1


    # def insert(self,inputRec):
    #     if self.isFull():
    #         print("hash table is full")
    #         return
        
    #     indexFound=False

    #     index=self.h1(inputRec.getNumber())
    #     print("dh index: ",inputRec)

    #     if self.Table[index]==None:
    #             self.Table[index]=inputRec
    #             print("table: ",self.Table[index])
    #             self.elecount+=1

    #     else:
    #         while  not indexFound:
    #             indexFound,index=self.DobleHashing(inputRec)
                
    #             if indexFound:
    #                 self.Table[index]=inputRec
    #                 self.elecount+=1


    def display(self):
            for x in range(self.size):
                   print("Hash Value: "+str(x) + "\t\t" + str(self.Table[x]))

        
    def search(self,inputRecord):
        found=False

        index=self.h1(inputRecord.getNumber());
        self.comparisons+=1

        if (self.Table[index]!=None):
            if(self.Table[index].getName()==inputRecord.getName()):
                    found=True
                    print("record is found at position ",index,"no of compariosons are:",self.comparisons)
            else:
                 print("record is not found")
        else:
            limit=self.size
            i=1
            while(i<limit):
                newindex=(self.h1(inputRecord.getNumber())+i*self.h2(inputRecord.getNumber()))%limit
                if(self.Table[newindex]!=None):
                    if(self.Table[newindex].getName()==inputRecord.getName()):
                            found=True
                            self.comparisons+=1
                            print("record is found at position ",index,"no of compariosons are:",self.comparisons)
                    else:
                         found=False
                         print("record is not found")
                         break
                else:
                     i+=1
            

        # if(found==False):
        #         print("record is not found")  
