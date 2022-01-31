def montagem(text1, text2):  
  # Cache the text lengths to prevent multiple calls.  
  text1_length = len(text1)  
  text2_length = len(text2)  
  # Eliminate the null case.  
  if text1_length == 0 or text2_length == 0:  
    return 0  
  # Truncate the longer string.  
  if text1_length > text2_length:  
    text1 = text1[-text2_length:]
    print('text1[-text2_length:]', text1)
  elif text1_length < text2_length:  
    text2 = text2[:text1_length]
    print('text2[:text1_length]', text2[:text1_length])
  # Quick check for the worst case.  
  if text1 == text2:  
    return min(text1_length, text2_length)  

  # Start by looking for a single character match  
  # and increase length until no match is found.  
  best = 0  
  length = 1  
  while True:  
    pattern = text1[-length:]
    print(pattern)
    found = text2.find(pattern)  
    if found == -1:  
      return best
    length += found  
    if text1[-length:] == text2[:length]:  
      best = length  
      length += 1


reads = ["atccat", "ccatg"]
montagem(reads[0], reads[1])
# maior_overlap = len(montagem(reads[0], reads[1]))
# res = montagem(reads[0], reads[1])
# flag = 1
# for i in range (len(reads)):
#     for j in range (len(reads)):
#             if(i != j):
#                 print(reads[i], reads[j])
#                 strmontagem = montagem(reads[i], reads[j])
#                 print('i ==',i,'j ==',j, 'resultou ==', strmontagem, end="\n")
#                 if(strmontagem != None):
#                     if(len(strmontagem) < maior_overlap):
#                         res = strmontagem
#                         maior_overlap = len(strmontagem)
#                         saved_i = i
#                         saved_j = j
# reads.append(res)

print(reads)
