local joinTable = function (t1, t2)
    for n,v in pairs(t2) do
        t1[n] = v
    end
    return t1
end

local M = {}
M = joinTable(M, require "tes3mp") -- Timer & Public APIs redefined by pluginlua
M = joinTable(M, require "Functions.Actors")
M = joinTable(M, require "Functions.Books")
M = joinTable(M, require "Functions.Cells")
M = joinTable(M, require "Functions.CharClass")
M = joinTable(M, require "Functions.Chat")
M = joinTable(M, require "Functions.Dialogue")
M = joinTable(M, require "Functions.Factions")
M = joinTable(M, require "Functions.GUI")
M = joinTable(M, require "Functions.Items")
M = joinTable(M, require "Functions.Mechanics")
M = joinTable(M, require "Functions.Miscellaneous")
M = joinTable(M, require "Functions.Objects")
M = joinTable(M, require "Functions.Positions")
M = joinTable(M, require "Functions.Quests")
M = joinTable(M, require "Functions.RecordsDynamic")
M = joinTable(M, require "Functions.Server")
M = joinTable(M, require "Functions.Settings")
M = joinTable(M, require "Functions.Shapeshift")
M = joinTable(M, require "Functions.Spells")
M = joinTable(M, require "Functions.Stats")
M = joinTable(M, require "Functions.Worldstate")

return M
