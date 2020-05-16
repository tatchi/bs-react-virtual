[@bs.deriving abstract]
type options = {
  size: int,
  parentRef: React.ref(Js.Nullable.t(Dom.element)),
  estimateSize: int => int,
  [@bs.optional]
  overscan: int,
  [@bs.optional]
  horizontal: bool,
};

type virtualRow = {
  index: int,
  start: int,
  size: int,
  [@bs.as "end"]
  end_: int,
};
type scrollToIndexOptions = {align: string};

type returnValue = {
  virtualItems: array(virtualRow),
  totalSize: int,
  // scrollToIndex:
  //   (~index: int, ~options: option(scrollToIndexOptions)) => unit,
};

[@bs.module "react-virtual"]
external useVirtual: options => returnValue = "useVirtual";

[@bs.send]
external scrollToIndex:
  (returnValue, ~index: int, ~options: scrollToIndexOptions=?, unit) => unit =
  "scrollToIndex";

[@bs.module "./index.js"]
external scrollToIndex2:
  (~index: int, ~options: option(scrollToIndexOptions)) => unit =
  "scrollToIndex";

let res = scrollToIndex2(~index=1, ~options=None);