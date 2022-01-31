def montagem(text1, text2):
    if(text1 == '' or text2 == ''):
        return
    aux1 = text1+text2
    aux2 = text1+text2

    x = min(len(text1), len(text2))
    y = max(len(text1), len(text2)) - min(len(text1), len(text2))
    while (x > 0):

        if text1[y:] == text2[:x]:
            aux1 = text1[:y] + text1[y:] + text2[x:]
        x -= 1
        y += 1
    x1 = x
    x = min(len(text1), len(text2))
    y = max(len(text1), len(text2)) - min(len(text1), len(text2))
    while (x > 0):
        if text2[y:] == text1[:x]:
            aux2 = text2[:y] + text2[y:] + text1[x:]
        x -= 1
        y += 1
    x2 = x
    if(len(aux1) == len(text1)):
        aux1 = ""
    if(len(aux2) == len(text2)):
        aux2 = ""    
    if(len(aux1) < len(aux2)):
        return aux1
    else:
        return aux2


reads = ["atccat", "ctgatc", "ccatg"]
maior_overlap = len(montagem(reads[0], reads[1]))
res = montagem(reads[0], reads[1])
flag = 1
for i in range (len(reads)):
    for j in range (len(reads)):
            if(i != j):
                print(reads[i], reads[j])
                strmontagem = montagem(reads[i], reads[j])
                print('i ==',i,'j ==',j, 'resultou ==', strmontagem, end="\n")
                if(strmontagem != None):
                    if(len(strmontagem) < maior_overlap):
                        res = strmontagem
                        maior_overlap = len(strmontagem)
                        saved_i = i
                        saved_j = j
reads.append(res)

print(reads)
