def pow(value, exponent):
    first_val = value
    for i in range(exponent-1): value *= first_val
    return value