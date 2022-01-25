def read_file(filename):
  with open(filename, "r") as f:
    data = f.read()
  board = data.split("\n\n")[0].split("\n")
  for i in range (len(board)):
    board[i] = board[i].split()
  words = data.split("\n\n")[1].split("\n")
  return board, words

def check_surrounding(i, j, w):
  found = False
  for r in range(-1,2):
    for c in range(-1,2):
      if not (r == 0 and c == 0):
        if (-1<=i+(len(w)*r) and (-1<=j+(len(w)*c)) and ((i+len(w)*r)<=len(board)) and ((j+len(w)*c)<=len(board[0]))):
          found = True
          for x in range(1, len(w)):
            if (board[i+(r*x)][j+(c*x)] != w[x]):
              found = False
              break
          if (found):
            return found
  return found

board, words = read_file("./Test-Cases/large2.txt")

for i in range (len(board)):
  for j in range (len(board[i])):
    for w in range (len(words)):
      curr_word = words[w]
      if (board[i][j] == curr_word[0]):
        found = check_surrounding(i, j, curr_word)
        if found:
          print(i, j, curr_word)