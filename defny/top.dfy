// Find the maximum value from a given array
method Maximum(values: seq<bv32>) returns (max: bv32)
  requires |values| == 4
  // requires values != []
  ensures max in values
  ensures forall i | 0 <= i < |values| :: values[i] <= max
{
  max := values[0];
  var idx : bv32 := 0;
  while (idx < |values| as bv32)
    invariant 0 <= idx <= |values| as bv32
    invariant max in values
    invariant forall j | 0 <= j < (idx as bv32) :: values[j] <= max
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