with Ada.Text_IO; use Ada.Text_IO;

procedure Debouncer is
   type Samples is array (Positive range <>) of Boolean;

   -- Require N consecutive opposing samples before changing stable state.
   function Stable_State (Input : Samples; Required : Positive) return Boolean is
      Current   : Boolean := False;
      Candidate : Boolean := False;
      Seen      : Natural := 0;
   begin
      for Value of Input loop
         if Value = Current then
            Candidate := Current;
            Seen := 0;
         else
            if Value = Candidate then
               Seen := Seen + 1;
            else
               Candidate := Value;
               Seen := 1;
            end if;
            if Seen >= Required then
               Current := Candidate;
               Seen := 0;
            end if;
         end if;
      end loop;
      return Current;
   end Stable_State;
begin
   if Stable_State ((True, False, True, False), 3) then
      raise Program_Error with "Glitch was not suppressed";
   end if;
   if not Stable_State ((False, True, True, True), 3) then
      raise Program_Error with "Stable transition was lost";
   end if;
   Put_Line ("Ada debouncer checks passed");
end Debouncer;
