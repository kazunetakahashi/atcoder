a, b = gets.chomp.split(" ").map{|i| i.to_i}
s = gets.chomp

ok = true
for i in 0...a+b+1
  if i == a
    if s[i] != '-'
      ok = false
    end
  else
    if s[i] == '-'
      ok = false
    end
  end
end

if ok
  puts "Yes"
else
  puts "No"
end
