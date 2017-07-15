n = gets.to_i
a = gets.chomp.split(" ").map{|i| i.to_i}.sort_by{|i|
  -1 * i.abs
}
x = 0
y = 0
a.each{|i|
  if (x < y && i > 0)
    x += i
  elsif (x < y && i <= 0)
    y += i
  elsif (x >= y && i > 0)
    y += i
  else
    x += i
  end
}
puts (x-y).abs
