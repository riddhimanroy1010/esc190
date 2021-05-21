def remove(L1, L2):
    removed = 0

    if len(L1) > len(L2):
        removed += abs(len(L1) - len(L2))
        i = removed
        for elems in L1:
            if elems not in L2:
                L1.remove(elems)
                i-= 1
            if i == 0:
                break
    
    return removed, L1, L2

def add(L1, L2):
    added = 0

    if len(L1) < len(L2):
        added += abs(len(L1) - len(L2))
        i = added
        for elems in L2:
            if elems not in L1:
                L1.append(elems)
                i-= 1
            if i == 0:
                break
    
    return added, L1, L2

def subsituted(L1, L2):

    substitutions = 0

    if len(L1) == len(L2):
        for i in range(len(L1)):
            if L1[i] != L2[i]:
                L1[i] = L2[i]
                substitutions += 1
    
    return substitutions, L1, L2

def construct_D_arr(L1, L2):

    D = [len(L1)][len(L2)]

    for i in range(len(L2)):
        D[i][0] = i

    for i in range(1, len(L2)):
        for j in range(len(L1)):
            removals, L1_r, L2_r = remove(L1[:i], L2[:j])
            additions, L1_a, L2_a = add(L1[:i], L2[:j])
            substitutions_r, L1, L2 = subsituted(L1_r[:i], L2_r[:j])
            substitutions_a, L1, L2 = subsituted(L1_a[:i], L2_a[:j])
            if removals == 0 and additions == 0:
                D[i][j] = min(substitutions_a, substitutions_r)
            else:
                D[i][j] = min(additions + substitutions_a, removals + substitutions_r)
            
    return D[i][j]

def min_dist(L1, L2):
    D = construct_D_arr(L1, L2)

    return D[len(L1)][len(L2)]

def recover_path(L1, L2):
    states = []
    '''go through the diagonal to get the transformations'''
    return



        

    




            