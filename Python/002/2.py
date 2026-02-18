def convert_value(value):
    # 1. Проверка на пустую строку
    if value == "":
        return ""
    
    # 2. Проверка на int
    if value.startswith("-"):
        if value[1:].isdigit():
            return int(value)
    elif value.isdigit():
        return int(value)
    
    # 3. Проверка на float
    if value.count(".") == 1:
        parts = value.split(".")
        left = parts[0]
        right = parts[1]
        
        if left.startswith("-"):
            left = left[1:]
        
        if left.isdigit() and right.isdigit():
            return float(value)
    
    # 4. В остальных случаях — строка
    return value


def read_text_file(filepath, delimiter=",", has_header=True):
    result = {
        "header": None,
        "data": [],
        "types": []
    }
    
    with open('/data', "r", ) as file:
        lines = file.readlines()
    
    lines = [line.strip() for line in lines if line.strip() != ""]
    
    start_index = 0
    
    # Заголовок
    if has_header:
        header = lines[0].split(delimiter)
        result["header"] = header
        start_index = 1
    
    if start_index >= len(lines):
        return result
    
    # Определяем типы по первой строке данных
    first_row = lines[start_index].split(delimiter)
    types = []
    
    for value in first_row:
        converted = convert_value(value)
        types.append(type(converted))
    
    result["types"] = types
    
    # Применяем преобразования ко всем строкам
    for line in lines[start_index:]:
        row = line.split(delimiter)
        converted_row = []
        
        for i in range(len(row)):
            value = row[i]
            
            if types[i] == int:
                converted_row.append(int(value))
            elif types[i] == float:
                converted_row.append(float(value))
            else:
                converted_row.append(value)
        
        result["data"].append(converted_row)
    
    return result
