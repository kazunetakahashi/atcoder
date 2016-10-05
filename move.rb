folder_name = "past_201510_201609"

Dir.open('.').each {|dir|
  if dir[0] == '0' || dir[0] == '1'
    puts dir
    system("git mv #{dir}/ #{folder_name}/")
  end
}
