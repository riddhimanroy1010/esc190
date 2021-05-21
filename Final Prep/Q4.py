import random


def norm(v, u):

    initial_normi = 0
    for i in range(len(u)):
        initial_normi = initial_normi + ((v[i] - u[i])**2)

    return initial_normi**0.5

def dnormdv(u, v):
    res = 0
    for i in range(len(u)):
        res = res + (-2 * (u[i] - v[i]))

    return res

'''
 GENERAL FORMULA:
 d(d)/dv = del(d)/del(norm1)* del(norm1)/del(v) + del(d)/del(norm2)* del(norm13/del(v) + del(d)/del(norm3)* del(norm3)/del(v)
 del(d)/del(norm_n) = 0.5*norm_n
 del(norm_n)/del(v) = sum(-2(u_n - v_n))

 changing v: based on the results for del(norm_v)/del(v)
 '''
def min_dist(u1, u2, u3):

    v = []
    for i in range(len(u1)):
        v.append(random.random)

    norm1 = norm(v, u1)
    norm2 = norm(v, u2)
    norm3 = norm(v, u3)

    delddelnorm1 = 0.5*norm1
    delddelnorm2 = 0.5*norm2
    delddelnorm3 = 0.5*norm3

    delnorm1delv = dnormdv(u1, v)
    delnorm2delv = dnormdv(u2, v)
    delnorm3delv = dnormdv(u3, v)

    delddelv = []

    delddelv.append(delddelnorm1 * delnorm1delv)
    delddelv.append(delddelnorm2 * delnorm2delv)
    delddelv.append(delddelnorm3 * delnorm3delv)

    for i in range(len(v)):
        v[i] += delddelv[i]

    return v
'''
u1 = [1.0, 2.0, 3.0]
u2 = [2.0, 3.0, 4.0]    
u3 = [4.0, 5.0, 6.0]

v = min_dist(u1, u2, u3)
'''











