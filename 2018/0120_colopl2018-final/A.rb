n = gets.to_i
s = gets.chomp
now = 0
ans = 0
s.chars{|c|
  if c == 'A'
    now += 1
    ans += now
  else
    now = 0
  end
}
puts ans
