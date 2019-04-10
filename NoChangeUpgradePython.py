def mymax(iterable, key = None):
    max_element = max_key = None

    if key is None:
        return max(iterable)

    it = iter(iterable)

    try:
        max_element = it.__next__()
    except StopIteration:
        return -1
    max_key = key(max_element)
    for item in iterable:
        current_key = key(item)
        if current_key > max_key:
            max_key = current_key
            max_element = item

    return max_element


int_list = [1, 5, 88, 99, 9, 1, 44]
print('Max INT in list: ', mymax(int_list))

print('Max CHAR in list(sentence)', mymax('Suncana strana ulice'))

print('Max ELEMENT in string list: ', mymax(['Gle', 'malu', 'vocku', 'poslije', 'kise',
                                             'Puna', 'je', 'kapi', 'pa', 'ih', 'njise']))

dictionary = {'Bread': 8, 'Donut': 5}
print('KEY for max VALUE in a dictionary: ', mymax(dictionary, key=dictionary.get))
