n = gets.to_i
s = []
s << gets.chomp
s << s+s
s << s+s+s
ans = [0, 0, 0]

isa = true
s[0].chars{|c|
  if c == 'B'
    isa = false
    break
  end
}

if isa
  m = s.size * n
  puts (m * (m+1))/2
  exit
end

for i in 0...3
  now = 0
  s[i].chars{|c|
    if c == 'A'
      now += 1
      ans[i] += now
    else
      now = 0
    end
  }  
end

k = ans[1] - ans[0]
l = ans[0]

puts k * (n-1) + l
