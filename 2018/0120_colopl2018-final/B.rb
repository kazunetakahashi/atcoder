s = gets.chomp

def henkan(str)
  op = str[0]
  if !['+', '-', '*', '/'].include?(op)
    return str
  end
  naka = str[2..-2]
  cnt = 0
  for i in 0...naka.size
    if naka[i] == '('
      cnt += 1
    elsif naka[i] == ')'
      cnt -= 1
    elsif naka[i] == ',' && cnt == 0
      naka[i] = '@'
    end
  end
  ary = naka.split('@')
  for i in 0...ary.size
    ary[i] = henkan(ary[i])
  end
  return '(' + ary.join(op) + ')'
end
