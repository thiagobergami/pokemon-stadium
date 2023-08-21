workspace "PokemonStadium"
    configurations {"Release"}

project "PokemonStadium"
    kind "ConsoleApp"
    language "C++"
    files {"%{prj.name}/includes/**.h", "%{prj.name}/src/**.cpp"}
    