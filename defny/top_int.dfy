// Declare bounded 32-bit integer type
const TWO_TO_THE_31: int := 0x8000_0000
newtype int32 = x: int | -TWO_TO_THE_31 <= x < TWO_TO_THE_31

// Find the maximum value from a given array
method Maximum(values: seq<int32>) returns (max: int32)
  requires |values| == 4
  // requires values != []
  ensures max in values
  ensures forall i | 0 <= i < |values| :: values[i] <= max
{
  max := values[0];
  var idx : int32 := 0;
  while (idx < |values| as int32)
    invariant 0 <= idx <= |values| as int32
    invariant max in values
    invariant forall j | 0 <= j < (idx as int32) :: values[j] <= max
  {
    if max < values[idx] {
      max := values[idx];
    }
    idx := idx + 1;
  }
}

// Simple test bench
method Main() {
  var x := Maximum([1, 2, 3, 4]);
  // expected to return 4
  print x, "\n";
}