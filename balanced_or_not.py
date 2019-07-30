def check_bal(string):
    open_braces = []
    closed_braces = []
    for i in string:
        if i in ['(','[','{']:
            open_braces.append(i)
        else:
            closed_braces.append(i)
    n = len(open_braces)
    open_braces.reverse()
    for i in range(n):
        try:
            if [open_braces[i],closed_braces[i]] == ['(',')'] or ['{','}'] or ['[',']']:
                pass
            else:
                return i,'unbalanced'
                break
        except:
            return i,'unbalanced'
    if len(closed_braces) != n:
        return i+1,'unbalanced'
    #returns index of open brace or closed brace and status of the string good string bad one
    return -1,'balanced'

while(1):
    string = input()
    index,_ = check_bal(string)
    if index == -1:
        print("braces are matched.")
    else:
        print(string)
        for i in range(len(string)):
            if string[i] == '(' or '{' or '[':
                if index == -1:
                    index = i
                    break
                index -= 1
        print('^'.rjust(index+1))

