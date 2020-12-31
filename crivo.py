import time

v = [7,11,13,17,19,23,29,31]
prime = []

def eliminaCompostos(n):
    notPrime = [False for i in range(n+1)] 

    i=0
    if(n>=2):
        prime.append(2)
    if(n>=3):
        prime.append(3)   
    if(n>=5):
        prime.append(5)
    while(True):
        j=i
        next=0
        col_i = i%8
        lin_i = i//8
        val_i = v[col_i]+30*lin_i
        col_j = j%8
        lin_j = j//8
        val_j = v[col_j]+30*lin_j
        if((val_i*val_j)>n):
            break
        if(notPrime[val_i]==False):
            prime.append(val_i)
        while(True):
            col_j = j%8
            lin_j = j//8
            val_j = v[col_j]+30*lin_j
            next = val_i * val_j
            if(next>n):
                break
            notPrime[next]=True
            j+=1
        i+=1
    while(val_i<=n):
        if(notPrime[val_i]!=1):
            prime.append(val_i)
        i+=1
        col_i=i%8
        lin_i=i//8
        val_i = v[col_i]+30*lin_i
    return prime


start_time = time.time()
a = eliminaCompostos(100000000)
print("Manso: --- %s seconds ---" % (time.time() - start_time))

