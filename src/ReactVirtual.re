// type options = {
//   size: int,
//   parentRef: React.ref(Js.Nullable.t(Dom.element)),
//   estimateSize: int => int,
// };

[@bs.deriving abstract]
type options = {
  size: int,
  parentRef: React.ref(Js.Nullable.t(Dom.element)),
  estimateSize: int => int,
  [@bs.optional]
  overscan: int,
  [@bs.optional]
  horizontal: bool,
  // [@bs.optional] scrollToFn: bool,
};

type virtualRow = {
  index: int,
  start: int,
  size: int,
  [@bs.as "end"]
  end_: int,
};

type returnValue = {
  virtualItems: Js.Array.t(virtualRow),
  totalSize: int,
};

[@bs.module "react-virtual"]
external useVirtual: options => returnValue = "useVirtual";