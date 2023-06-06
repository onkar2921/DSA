from Record import Record 
record=Record()
class HashTable:

    def __init__(self):
        self.size=int(input("enter the size of hash table: "))
        self.eleCount=0
        self.comparisons=0
        self.Table=list(None for i in range(self.size))
        
    def isFull(self):
        if self.eleCount==self.size:
            return True
        else:
            return False
        
    def HashFunction(self,ele):
        return ele % self.size
    
    
    def insertInHashTable(self,inputrecord):
        
        if self.isFull():
            print("hash table is full")
            return
        
     

        index=self.HashFunction(inputrecord.getNumber())

        if self.Table[index]==None:
            self.Table[index]=inputrecord
            print("record inserted sucessfully")
            
            self.eleCount+=1

        else:
            # print("solving collision")

            while (self.Table[index]!=None):
                index+=1
                if index >=self.size:
                    index=0

                
            self.Table[index]=inputrecord
            # print("recored inserted after collision")
            self.eleCount+=1

        

    def display(self):
            for x in range(self.size):
                   print("Hash Value: "+str(x) + "\t\t" + str(self.Table[x]))


          




    def searchRecord(self,searchRec):
        

        
        if self.eleCount==None:
            print("nothing in hash table")
            return
        
        # element=searchRec.getNumber()
        # index=self.HashFunction(element)

        index=self.HashFunction(searchRec.getNumber())
        self.comparisons+=1

        # print("index ",index)
        # print("table data:",self.Table[index])
        if (self.Table[index]!=None):
            if(self.Table[index].getName()==searchRec.getName() and self.Table[index].getNumber()==searchRec.getNumber()):
                # print("hello")
               
                print("recordd is found at index: ",index, "record is :",searchRec.getName())
            else:
                print("record is not found")   
        else:
            # index+=1
            # if index>= self.size:
            #     index=0
            # while  ( self.Table[index]!=None or self.comparisons<=self.size ):

            #     if( self.Table[index].getName()==searchRec.getName() and self.Table[index].getNumber()==searchRec.getNumber()):
                    
            #         self.comparisons+=1
            #         print("recordd is found at index: ",index, "record is :",searchRec.getName())
            #     else:
                    # print("record is not found")  

            found=0
            while( self.comparisons==self.size):
                index+=1
                self.comparisons+=1
                if(index==self.size):
                    index=0

                if(self.Table[index].getName()==searchRec.getName() and self.Table[index].getNumber()==searchRec.getNumber()):
                    print("found")
                    found=1
                    break
                else:
                    print("not found")
                    found=0  
            
            if(found):
                print("found")
            else:
                print("not found")


# name=input("enter the name")
# number=int(input("enter the number:"))
# Record.setName(name)
# Record.setNumber(number)
# name=input("enter the name")
# number=int(input("enter the number:"))
# Record.setName(name)
# Record.setNumber(number)5

# name=input("enter the name")
# number=int(input("enter the number:"))
# Record.setName(name)
# Record.setNumber(number)

# obj1=HashTable()

# in1=Record()

# in1.setName("onkar")
# in1.setNumber(1)
# obj1.insertInHashTable(in1)

# in2=Record()
# in2.setName("vinod")
# in2.setNumber(2)
# obj1.insertInHashTable(in2)

# in3=Record()
# in3.setName("kakade")
# in3.setNumber(3)
# obj1.insertInHashTable(in3)


# # obj1=HashTable()
# # obj1.insertInHashTable(record)

# obj1.display()


# seacrhRC=Record()
# seacrhRC.setName("onkar")
# seacrhRC.setNumber(1)

# obj1.searchRecord(seacrhRC)


# obj1=HashTable()
# while(True):
#     ch=int(input("enter your choice:"))

#     if(ch==1):
#         record=Record()
#         record.setName(input("enter the name"))
#         record.setNumber(int(input("enter the number")))
#         obj1.insertInHashTable(record)

#     if(ch==2):
#         obj1.display()

#     if(ch==3):
#         seacrhRC=Record()
#         seacrhRC.setName("vinod")
#         seacrhRC.setNumber(2)
#         obj1.searchRecord(seacrhRC)
 


