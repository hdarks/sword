def xor_and_with_127(input_string):
    result = ""
    for char in input_string:
        result += chr(ord(char) & 127)
    print("After bitwise AND with 127: ",result)

    for char in input_string:
        result += chr(ord(char) ^ 127)
    print("After bitwise XOR with 127: ",result)

input_string = "\HelloWorld"
print("Original String:", input_string)
xor_and_with_127(input_string)