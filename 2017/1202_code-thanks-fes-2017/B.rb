s = gets.chomp
t = s.reverse
for i in 0...t.size
  u = s + t[t.size-i...t.size]
  if u == u.reverse
    puts u.size - s.size
    exit
  end
end
