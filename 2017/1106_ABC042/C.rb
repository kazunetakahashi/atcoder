n, k = gets.chomp.split(" ").map{|i| i.to_i}
d = gets.chomp.split(" ").map{|i| i.to_s}
for i in n...1000000
  ok = true
  i.to_s.chars{|c|
    if d.include?(c)
      ok = false
      break
    end
  }
  if ok
    puts i
    exit
  end
end
