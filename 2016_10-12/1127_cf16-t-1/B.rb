@k = gets.to_i
@s = gets.chomp

def dfs(str, num, pl)
  if pl >= str.size()
    return nil
  end
  if num == 0
    # puts str
    return str.split(",").map{|x| x.to_i}.max
  else
    ans = @s.to_i
    for i in num..str.size()-1
      a = str.clone
      new = a.insert(i, ',')
      f = dfs(new, num-1, i+1)
      ans = [ans, f].min if !f.nil?
    end
    return ans
  end
end

puts dfs(@s, @k, 1)

