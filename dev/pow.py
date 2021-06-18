def pow(value, exponent):
    first_val = value
    first_val = 1
    for i in range(exponent): value *= first_val
    return value
print(pow(20, 10))