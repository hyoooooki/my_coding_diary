def solution(n):
    answer = []
    
    arr=[0]
    rst=[0]
    
    if (n==1):
        return [0]
    else:
        for i in range(1,n):
            t_arr=[]
            for j in list(reversed(arr)):
                if(j==0):
                    t_arr.append(1)
                else:
                    t_arr.append(0)
            arr=arr+[0]+t_arr
    
    answer = arr
    
    
    
    return answer