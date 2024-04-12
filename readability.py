
def count_words(s):
    """
    #words = len([word for word in s.split() if word.isalpha()])
    words = 1
    w = [' ',',']
    for i in s:
        if str(i) in w:
            words += 1;
    return words
    """
    count = 0
    for words in s.split():
        try:
            int(words)
        except ValueError:
            count += 1
    return count

def count_sentences(s):

    sentences = 0
    w = ['?', '.', '!']
    for i in s:
        if str(i) in w:
            sentences += 1
    return sentences


def count_letters(s):

    letters = 0
    w = [' ', '.', '!', '?', ',', '\'', '"']
    for i in s:
        if str(i) not in w:
            letters += 1
    # print(f'letters are : {letters}', end="\n")
    return float(letters)

def main():

    s = input("Input a string: \n")

    L = count_letters(s) * 100 / count_words(s)
    S = count_sentences(s) * 100 / count_words(s)

    index = float((0.0588 * L) - (0.296 * S) - 15.8)
    ind = round(index)

    if ind >= 16:
        {
            print('Grade 16+', end="\n")
        }
    elif 10 <= ind < 16:
        {
            print('Grade 10', end="\n")
        }
    elif ind == 9:
        {
            print(f'Grade {ind}', end="\n")
        }
    elif ind == 8:
        {
            print(f'Grade {ind}', end="\n")
        }
    elif ind == 7:
        {
            print(f'Grade {ind}', end="\n")
        }
    elif 5 <= ind < 7:
        {
            print('Grade 5', end="\n")
        }
    elif 3 <= ind < 5:
        {
            print('Grade 3', end="\n")
        }
    elif ind == 2:
        {
            print(f'Grade {ind}', end="\n")
        }
    elif ind == 1:
        {
            print(f'Grade{ind}', end="\n")
        }
    elif ind < 1:
        {
            print('Before Grade 1', end="\n")
        }
    else:
        {
            print('Invalid', end="\n")
        }


main()
