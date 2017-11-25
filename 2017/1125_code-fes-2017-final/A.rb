s = gets.chomp
t = "AKIHABARA"
i = 0
j = 0
while i < s.size() && j < t.size()
  if s[i] == t[j]
    t[j] = "A"
    i += 1
    j += 1
  else
    j += 1
  end
end

if i < s.size()
  puts "NO"
else
  for k in 0...t.size()
    if t[k] != "A"
      puts "NO"
      exit
    end
  end
  puts "YES"
end
