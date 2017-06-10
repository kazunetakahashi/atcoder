n = gets.to_i
s = gets.chomp
need = 0
right = 0
s.chars{|c|
  if c == '('
    right -= 1
  else
    right += 1
  end
  need = [need, right].max
}
need.times {
  s = '(' + s
}
left = 0
right = 0
s.chars{|c|
  if c == '('
    left += 1
  else
    right += 1
  end
}
(left - right).times{
  s = s + ')'
}
puts s

